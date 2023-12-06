using Microsoft.AspNetCore.Identity;


// PASUL 1 - useri si roluri 
namespace ArticlesApp.Models 
{
    public class ApplicationUser : IdentityUser
    {
        // un user poate posta mai multe comentarii
        public virtual ICollection<Comment>? Comments { get; set; }

        // un user poate posta mai multe articole
        public virtual ICollection<Article>? Articles { get; set; }

        //un user creeaza mai multe colectii
        public virtual ICollection<Bookmark> Bookmarks { get; set; }


        //atribute suplimentare adaugate pentru user
        public string? FirstName { get; set; }

        public string? LastName { get; set;}



    }
}
