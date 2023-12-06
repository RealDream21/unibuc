using System.ComponentModel.DataAnnotations.Schema;

namespace ArticlesApp.Models
{
    //tabelul asociativ care face lagatura dintre 
    //Article si Bookmark
    //Un articol face parte din mai multe colectii
    //O colectie contine mai multe articole
    public class ArticleBookmark
    {
        [DatabaseGenerated(DatabaseGeneratedOption.Identity)]//Id-ul creste automat cand adaugam
        public int Id { get; set; } 

        public int? ArticleId {  get; set; }

        public int? BookmarkId {  get; set; }
        public DateTime BookmarkDate {  get; set; }

        public virtual Article? Article {  get; set; }
        public virtual Bookmark? Bookmark { get; set; }


    }
}
