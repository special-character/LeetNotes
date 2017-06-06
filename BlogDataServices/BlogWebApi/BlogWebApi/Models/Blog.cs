using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace BlogWebApi.Models
{
    public class Blog
    {
        public int id { get; set; }
        public string content { get; set; }
        public string author { get; set; }
        public string blogType { get; set; } 
        public List<string> tags { get; set; }


        public static List<string> buildTags (string tagString)
        {
            string[] words = tagString.Split(default(string[]), StringSplitOptions.RemoveEmptyEntries);
            var stringList = words.Select(tag => tag).ToList(); 
            return stringList;
        }
    }
}