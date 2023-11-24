using System.ComponentModel.DataAnnotations;

namespace ArticlesApp.Models
{
    public class Comment
    {
        [Key]
        public int Id { get; set; }

        [Required(ErrorMessage = "Continutul este obligatoriu")]
        public string Content { get; set; }

        [Required(ErrorMessage ="Data este obligatorie")]
        public DateTime Date { get; set; }

        [Required(ErrorMessage ="ID-ul articolului este oblgiatoriu")]
        public int ArticleId { get; set; }

        public virtual Article Article { get; set; }
    }

}
