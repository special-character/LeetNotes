type markdown;
type converted;

/*external markdown : unit => markdown = "markdown" [@@bs.module "showdown"];*/

external ttt : unit => markdown  = "Converter" [@@bs.new][@@bs.module "showdown"];
external makeHtml : markdown => string => ReactRe.reactElement = "makeHtml" [@@bs.send];
