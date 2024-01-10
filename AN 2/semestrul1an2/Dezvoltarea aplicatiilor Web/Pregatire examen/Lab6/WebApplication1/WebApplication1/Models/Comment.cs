using System.ComponentModel.DataAnnotations;

namespace WebApplication1.Models
{
    public class Comment
    {
        [Key]
        public int Id { get; set; }
        public string Content { get; set; }
        public DateTime date { get; set; }
        public int ArticleId { get; set; }
        public virtual Article Article { get; set; }    
    }
}
