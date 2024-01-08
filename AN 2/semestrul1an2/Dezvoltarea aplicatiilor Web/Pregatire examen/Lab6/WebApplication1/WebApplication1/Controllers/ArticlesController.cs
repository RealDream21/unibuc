using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.EntityFrameworkCore;
using System.Security.Cryptography;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class ArticlesController : Controller
    {
        private readonly AppDbContext db;
        public ArticlesController(AppDbContext context)
        {
            db = context;
        }


        public IActionResult Index()
        {
            var articles = from article in db.Articles select article;
            ViewBag.Articles = articles;

            Console.WriteLine(DateTime.Now.ToString());

            return View();
        }

        public IActionResult Show(int id)
        {
            var article = db.Articles.Include("Category").Include("Comments")
                            .Where(art => art.Id == id)
                            .First();
            ViewBag.Article = article;
            return View();
        }

        public IActionResult New()
        {
            ViewBag.Categ = GetAllCategories();
            //Article article = new Article();
            return View();
        }

        [HttpPost]
        public IActionResult New(Article reqArticle)
        {
            Console.WriteLine("++++++++++++++++" + reqArticle.Title);

            try
            {
                db.Articles.Add(reqArticle);
                reqArticle.date = DateTime.Now;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            catch (Exception)
            {
                return View();
            }
        }

        public IActionResult Edit(int id)
        {
            var article = db.Articles.Include("Category").Where(art => art.Id == id).First();
            ViewBag.Article = article;
            ViewBag.Categ = GetAllCategories();
            return View();
        }

        [HttpPost]
        public IActionResult Edit(int id, Article reqArticle)
        {
            Article article = db.Articles.Find(id);
            try
            {
                article.Title = reqArticle.Title;
                article.Content = reqArticle.Content;
                article.date = DateTime.Now;
                article.CategoryId = reqArticle.CategoryId;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            catch (Exception)
            {
                return RedirectToAction("Edit", article.Id);
            }
        }

        [HttpPost]
        public IActionResult Delete(int id)
        {
            Article article = db.Articles.Find(id);
            db.Articles.Remove(article);
            db.SaveChanges();
            return RedirectToAction("Index");
        }



        ///CHESTII NOT MAPPED\\\
        public IEnumerable<SelectListItem> GetAllCategories()
        {
            var selectList = new List<SelectListItem>();

            var categories = from cat in db.Categories select cat;

            foreach (var category in categories)
            {
                selectList.Add(new SelectListItem
                {
                    Value = category.Id.ToString(),
                    Text = category.CategoryName.ToString()
                });
            }
            return selectList;
        }

    }
}
