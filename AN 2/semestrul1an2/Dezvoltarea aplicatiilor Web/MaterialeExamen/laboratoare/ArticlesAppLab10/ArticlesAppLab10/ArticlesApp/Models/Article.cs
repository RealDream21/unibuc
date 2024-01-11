using Microsoft.AspNetCore.Mvc.Rendering;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ArticlesApp.Models
{
    public class Article
    {
        [Key]
        public int Id { get; set; }

        [Required(ErrorMessage = "Titlul este obligatoriu")]
        [StringLength(100, ErrorMessage = "Titlul nu poate avea mai mult de 100 de caractere")]
        [MinLength(5, ErrorMessage = "Titlul trebuie sa aiba mai mult de 5 caractere")]
        public string Title { get; set; }

        [Required(ErrorMessage = "Continutul articolului este obligatoriu")]
        public string Content { get; set; }

        public DateTime Date { get; set; }

        [Required(ErrorMessage = "Categoria este obligatorie")]
        // un articol are asociata o categorie
        public int? CategoryId { get; set; }

        // un articol este postat de catre un user
        public string? UserId { get; set; }

        // PASUL 6 - useri si roluri
        public virtual ApplicationUser? User { get; set; }

        public virtual Category? Category { get; set; }

        // un articol poate avea o colectie de comentarii
        public virtual ICollection<Comment>? Comments { get; set; }

        [NotMapped]
        public IEnumerable<SelectListItem>? Categ { get; set; }

        // relatia many-to-many dintre Article si Bookmark
        public virtual ICollection<ArticleBookmark>? ArticleBookmarks { get; set; }
    }

}


