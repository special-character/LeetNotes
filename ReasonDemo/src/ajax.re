type xmlt; 
type promt;
type jsonr;
type reject_obj = {. message:string, status:string };
type handler = (string=> unit) => (reject_obj => unit) => unit;

external req_open : xmlt => string => string => unit = "open" [@@bs.send];
external req_set_header : xmlt => string => string => unit = "open" [@@bs.send];
external req_send : xmlt => string => unit = "send" [@@bs.send];

external req_set_on_error : xmlt => (unit => unit) => unit = "onerror" [@@bs.set];
external get_req_responseText : xmlt => string = "responseText" [@@bs.get];
external get_req_responseStatus : xmlt => string = "status" [@@bs.get];

external req_set_on_load : xmlt => (unit => unit) => unit = "onload" [@@bs.set];

external xmlhttprequest : unit => xmlt  = "XMLHttpRequest" [@@bs.new];
external create_promise : handler => promt = "Promise" [@@bs.new];

external unsafeJsonParse : string => jsonr = "JSON.parse" [@@bs.val];
external unsafeJsonStringify : jsonr => string = "JSON.stringify" [@@bs.val];
 
 let ajaxPost = fun url data => {
    let promise = create_promise (fun res rej => {
    
        let req = xmlhttprequest();
        req_open req "GET" url; 
        req_set_header req "Content-Type" "application/json; charset=utf-8";
        req_set_header req "Accept" "application/json, text/javascript";

        req_set_on_error req (fun () => {
            rej { pub message = get_req_responseStatus req ; 
              pub status = get_req_responseStatus req;
            };
            Js.log "Request failed";
        });

        req_set_on_load req (fun () => {
            let status = get_req_responseStatus req;
            switch status {
                | "200" => res (unsafeJsonParse (get_req_responseText req));
                | _     => rej { pub message = get_req_responseStatus req ; 
                            pub status = get_req_responseStatus req;
                        };
            };

            Js.log "Request succeded";
        });

        req_send req (unsafeJsonStringify data);

    });

    promise;
 };