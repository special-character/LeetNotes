type markdown;
type converted;


external mdInit : unit => markdown  = "Converter" [@@bs.new][@@bs.module "showdown"];
external makeHtml : markdown => string => ReactRe.reactElement = "makeHtml" [@@bs.send];
