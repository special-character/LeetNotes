open Pervasives;
type xmlt; 
type promt;
type reject_obj = {. message:string, status:string };
type handler = int => (reject_obj => unit) => unit;

external req_open : xmlt => string => string => unit = "open" [@@bs.send];
external req_set_header : xmlt => string => string => unit = "open" [@@bs.send];

external req_set_on_error : xmlt => (unit => unit) => unit = "onerror" [@@bs.set];
external get_req_responseText : xmlt => string = "responseText" [@@bs.get];
external get_req_responseStatus : xmlt => string = "status" [@@bs.get];

external req_set_on_load : xmlt => (unit => unit) => unit = "onload" [@@bs.set];

external xmlhttprequest : unit => xmlt  = "XMLHttpRequest" [@@bs.new];
external create_promise : handler => promt = "Promise" [@@bs.new];

external unsafeJsonParse : string => 'a = "JSON.parse" [@@bs.val];

 
 let ajaxPost = fun url data => {
    let promise = create_promise (fun res rej => {
    
        let req = xmlhttprequest();
        req_open req "POST" url; 
        req_set_header req "Content-Type" "application/json; charset=utf-8";
        req_set_header req "Accept" "application/json, text/javascript";

        req_set_on_error req (fun () => {
            { pub message = get_req_responseStatus req ; 
              pub status = get_req_responseStatus req;
            };
            Js.log "Request failed";
        });

        req_set_on_load req (fun () => {
            
            Js.log "Request succeded";
        });

    });

    promise;
 };