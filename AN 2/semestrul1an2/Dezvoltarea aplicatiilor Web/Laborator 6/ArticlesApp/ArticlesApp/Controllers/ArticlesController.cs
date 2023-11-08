using ArticlesApp.Data;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace ArticlesApp.Controllers
{
    public class ArticlesController : Controller
    {

        private readonly ApplicationDbContext db;

        public ArticlesController(ApplicationDbContext context)
        {
            db = context;
        }

        public IActionResult Index()
        {
            var articles = db.Articles.Include("Category");
            /*var articles = from art in db.Articles
                           orderby art.Date descending
                           select art;*/
            ViewBag.Articles = articles;
            return View();
        }
    }
}
