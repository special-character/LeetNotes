
type xmlt; 
type promt;
type handler = int => int => unit;

external req_open : xmlt => string => string => unit = "open" [@@bs.send];
external req_set_header : xmlt => string => string => unit = "open" [@@bs.send];
/*external req_set_on_error : xmlt => string => unit = "onerror" [@@bs.set];*/
external req_set_on_error : xmlt => (unit => string) => unit = "onerror" [@@bs.set];


external xmlhttprequest : unit => xmlt  = "XMLHttpRequest" [@@bs.new];
external create_promise : handler => promt = "Promise" [@@bs.new];

 let ajaxPost = fun url data => {
    let promise = create_promise (fun res rej => {
    
        let req = xmlhttprequest();
        req_open req "POST" url; 
        req_set_header req "Content-Type" "application/json; charset=utf-8";
        req_set_header req "Accept" "application/json, text/javascript";

        /*req_set_on_error req "a"; */
        let a = fun ()=> "chris";

        req_set_on_error req a;

    });
 };