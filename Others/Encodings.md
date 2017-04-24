##Encodings and Character Sets History 

Encodings such as  ASCII were used
* 0-31 were control characters
* 32-127 were alpha or numeric
* For the high order bit, many people did whatever they wanted with 128-255

ANSI got together.  Said 0-128 would remain the same (ASCII), but code pages were going to be used for everything above.  This didn't completely work, as people still just pretended that one byte translated to a single character.  People resorted to not really being able to read strings in other languages.

Then Unicode came along.  Unicode works a little differently.  A letter (character) used to map to a byte (8 bits).  Now characters map to __code points__.  Some people are under the misconception that Unicode is a 16 bit character set.  Not the case.  The below is the word 'Hello' in Unicode: U+0048 U+0065 U+006C U+006C U+006F.


People ignored Unicode.  The initial idea of the encoding was to store each code point as two bytes.  00 48 00 65 00 6c 00 6c 006f.  American's didn't like this.  This was referred to as UTF-16.  

UTF-8 was finally created and people loved that.  1-128 was stored in only one byte and anything Unicode wise above that utilized more bytes if need be.  This was more efficient.  English in UTF-8 looked just like ASCII which was a big plus.  

Regarding web servers, browsers, and an html page...we have to put the character encoding set in the meta tag at the top of the page so the browser understands how to parse strings.  

Aside: when you had to use wchar in c++, this was because OLEDB needed two byte unicode (UCS-2).  
