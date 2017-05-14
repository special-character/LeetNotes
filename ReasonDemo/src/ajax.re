
type xmlt; 
type promt;
type handler = int => int => unit;
external req_open : xmlt => string => string => unit = "open" [@@bs.send];


external xmlhttprequest : unit => xmlt  = "XMLHttpRequest" [@@bs.new];
external create_promise : handler => promt = "Promise" [@@bs.new];

 let ajaxPost = fun url data => {
    let promise = create_promise (fun res rej => {
    
        let req = xmlhttprequest();
        req_open req "POST" url; 
        let a = 8;
    });
 };