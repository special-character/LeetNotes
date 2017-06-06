type dom;
type id;

external document : dom = "document" [@@bs.val];
external get_by_id : dom => string => id = "getElementById" [@@bs.send];
external get_attribute : (id) => string => string = "getAttribute" [@@bs.send];

let app = get_by_id document "app";


let endpointApiRequestFormatter = fun (method)  => {
    let undefined = Js.Null_undefined.return (app)
                    |> Js.Null_undefined.test
                    |> Js.Boolean.to_js_boolean;

    undefined == Js.true_ 
    ? "" 
    : ((get_attribute (app) "dataServiceEndpoint") ^ (method));
};    
