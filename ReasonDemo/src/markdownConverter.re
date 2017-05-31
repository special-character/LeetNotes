type markdown;
type converted;


external ttt : unit => markdown  = "Converter" [@@bs.new][@@bs.module "showdown"];
external makeHtml : markdown => string => ReactRe.reactElement = "makeHtml" [@@bs.send];
