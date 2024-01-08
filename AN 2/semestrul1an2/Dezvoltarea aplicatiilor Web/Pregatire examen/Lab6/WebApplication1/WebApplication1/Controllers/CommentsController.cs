using Microsoft.AspNetCore.Mvc;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class CommentsController : Controller
    {

        private readonly AppDbContext db;
        public CommentsController(AppDbContext context)
        {
            db = context;
        }

        [HttpPost]
        public IActionResult New(Comment reqComment)
        {
            try
            {
                Console.WriteLine("A FOST ADAUGAT COMENTARIUL");
                reqComment.date = DateTime.Now;
                db.Comments.Add(reqComment);
                db.SaveChanges();
                return Redirect("/Articles/Show/" + reqComment.ArticleId);
            }
            catch(Exception)
            {
                Console.WriteLine("NU A FOST ADAUGAT COMENTARIUL");
                return Redirect("/Articles/Index");
            }

        }


    }
}
