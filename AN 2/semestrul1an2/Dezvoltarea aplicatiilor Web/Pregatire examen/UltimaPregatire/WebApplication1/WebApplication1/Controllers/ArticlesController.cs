using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Rendering;
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

        public IActionResult New()
        {
            Article article = new Article();
            article.Categ = GetAllCategories();
            return View(article);
        }

        [HttpPost]
        public IActionResult New(Article article)
        {
            article.Date = DateTime.Now;

            if (ModelState.IsValid)
            {
                db.Add(article);
                db.SaveChanges();
                return Redirect("Index");
            }
            else
            {
                return View();
            }
        }


        public IEnumerable<SelectListItem> GetAllCategories()
        {
            // generam o lista de tipul SelectListItem fara elemente
            var selectList = new List<SelectListItem>();
            // extragem toate categoriile din baza de date
            var categories = from cat in db.Categories
                             select cat;
            // iteram prin categorii
            foreach (var category in categories)
            {
                selectList.Add(new SelectListItem
                {
                    Value = category.Id.ToString(),
                    Text = category.Title.ToString()
                });
            }
            /* Sau se poate implementa astfel: 
            * 
            foreach (var category in categories)
            {
            var listItem = new SelectListItem();
           listItem.Value = category.Id.ToString();
           listItem.Text = category.CategoryName.ToString();
            selectList.Add(listItem);
            }*/

            // returnam lista de categorii
            return selectList;
        }
    }
}
