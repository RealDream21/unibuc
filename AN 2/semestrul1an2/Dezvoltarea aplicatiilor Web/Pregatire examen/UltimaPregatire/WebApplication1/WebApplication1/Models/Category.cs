using System.ComponentModel.DataAnnotations;

namespace WebApplication1.Models
{
    public class Category
    {
        [Key]
        public int Id { get; set; }

        public string Title {  get; set; }

        public virtual ICollection<Article> Articles { get; set;}

    }
}
