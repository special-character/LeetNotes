type dom;
type id;
type urlSpec = {attr: string, endpoint: string};
type product = Cube | QE | Tutorial | Adhoc;


external document : dom = "document" [@@bs.val];
external get_by_id : dom => string => id = "getElementById" [@@bs.send];
external get_attribute : (unit => id) => string => string = "getAttribute" [@@bs.send];

let getProduct = fun (prod:product) => {
    switch prod {
    | Cube => 0;
    | QE => 1;
    | Tutorial => 2;
    | Adhoc => 3;
    };
};
let app () => {
    let marker = get_by_id document "app"
                 |> Js.Null_undefined.return  
                 |> Js.Null_undefined.test;

    switch marker {
    | true  => get_by_id document "cubeBrowserApp";
    | false =>  get_by_id document "app";
    };
};

let urlFormatter = fun (spec:urlSpec)  => {
    let defined = Js.Null_undefined.return app
                  |> Js.Null_undefined.test;
    
    defined ? ((get_attribute app (spec.attr) ) ^ (spec.endpoint)) : "";
};    


let endpoints = [
                  {attr:"cubeDataServiceurl", endpoint:"/api/CubeData/"},
                  {attr:"queryDataServiceurl", endpoint:"/api/QueryExpressData/"},
                  {attr:"tutorialDataServiceurl", endpoint:"/api/TutorialData/"},
                  {attr:"adhocDataServiceurl", endpoint:""}
                 ]
                 |> List.map (fun x => urlFormatter x);


let a = List.nth endpoints (getProduct QE); 