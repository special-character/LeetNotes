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
    }
}