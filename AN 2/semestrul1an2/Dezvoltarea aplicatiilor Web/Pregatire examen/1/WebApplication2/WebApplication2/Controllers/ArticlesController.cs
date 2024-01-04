using Microsoft.AspNetCore.Mvc;
using WebApplication2.Models;

namespace WebApplication2.Controllers
{
    public class ArticlesController : Controller
    {
        public IActionResult Index()
        {
            Article[] articles = GetArticles();
            ViewBag.Articles = articles;
            return View();
        }

        public IActionResult Show(int? id)
        {
            Article[] articles = GetArticles();
            try
            {
                ViewBag.Article = articles[(int)id];
                return View();
            }
            catch (Exception ex)
            {
                ViewBag.ErrorMessage = ex.Message;
                return View("Error");
            }

        }

        [HttpGet]
        public IActionResult New()
        {
            return View();
        }

        [HttpPost]
        public IActionResult New(Article article)
        {
            return View("NewPostMethod");
        }

        [NonAction]
        public Article[] GetArticles()
        {
            Article[] articles = new Article[3];
            for (int i = 0; i < 3; i++)
            {
                Article article = new Article();
                article.Id = i;
                article.Title = "Articol " + (i + 1).ToString();
                article.Content = "Continut Articol" + (i + 1).ToString();
                article.Date = DateTime.Now;
                articles[i] = article;
            }
            return articles;
        }
    }
}
