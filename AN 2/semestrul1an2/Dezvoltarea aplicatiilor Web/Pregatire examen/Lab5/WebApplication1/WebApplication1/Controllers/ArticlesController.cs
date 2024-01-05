using Microsoft.AspNetCore.Mvc;
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


            return View();
        }

        public IActionResult Show(int? id)
        {
            var article = db.Articles.Where(a => a.Id == id).First();


            ViewBag.Article = article;
            return View();

        }


        public IActionResult New()
        {
            return View();
        }

        [HttpPost]
        public IActionResult New(Article article)
        {
            try
            {
                article.date = DateTime.Now;
                db.Articles.Add(article);
                db.SaveChanges();
                return RedirectToAction("index");
            }
            catch(Exception)
            {
                return View();
            }
        }

        public IActionResult Edit(int id)
        {
            var article = db.Articles.Where(a => a.Id == id).First();
            ViewBag.Article = article;
            return View();
        }

        [HttpPost]
        public IActionResult Edit(int id, Article reqarticle)
        {
            Article article = db.Articles.Find(id);
            try
            {
                article.date = DateTime.Now;
                article.Title = reqarticle.Title;
                article.Content= reqarticle.Content;
                db.SaveChanges();
                return RedirectToAction("index");
            }
            catch(Exception)
            {
                return RedirectToAction("Edit", article.Id);
            }
        }

        public IActionResult Delete(int id)
        {
            Article article =db.Articles.Find(id);
            db.Articles.Remove(article);
            db.SaveChanges();
            return RedirectToAction("index");
        }


    }
}
