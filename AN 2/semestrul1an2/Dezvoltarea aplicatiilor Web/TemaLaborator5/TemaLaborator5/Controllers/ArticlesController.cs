using Microsoft.AspNetCore.Mvc;
using TemaLaborator5.Models;

namespace TemaLaborator5.Controllers
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
            var articles = from article in db.Articles
                           select article;
            ViewBag.Articles = articles;

            return View();
        }
    }
}
