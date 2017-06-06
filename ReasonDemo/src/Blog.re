open Pervasives;
open ReactRe;
open Markdown; 

module Blog = {
    
    include ReactRe.Component.Stateful;
    type contentItem = {
        id: string,
        content: string,
        author: string,
        blogType: string,
        tags: list string
    };
    type props = unit;
    type state = {
        contentList : list contentItem  
    };
    let name = "Blog";

    let handleData {setState} data => {

        let stateSetter {state} => { 
            
            let blogList =
            data##blogList
            |> Array.to_list
            |> List.map (fun bp => {   id:bp##id,    
                                       content:bp##content,
                                       author:bp##author,
                                       blogType:bp##blogType,
                                       tags:bp##tags
                                   });

            {...state, contentList : blogList}
        };
        setState stateSetter;
        None
    };

    let getInitialState props => { 
        contentList : [] 
    };

    let componentDidMount {state, setState, handler, updater} => {        
        
        updater handleData
        |> Ajax._then (Ajax.ajaxPost (DocElements.endpointApiRequestFormatter "blogs") );
        None; 
    };
    
    let render {state, props, updater} => {

    let { contentList } = state;
    let colorConverter color =>
        switch color {
        | "FrontEnd" => "success"
        | "BackEnd" => "warning"
        };
    
    let nameBadge name badgeColor => <Label bsStyle=(colorConverter badgeColor)>
                                         (ReactRe.stringToElement name)
                                     </Label>;

    let blogPosts =
        contentList
        |> List.map (fun x =>  
        <Row>
            <Col md=12>
                <Panel header=(nameBadge x.blogType x.blogType)>
                    <Markdown markup=x.content/>
                </Panel>
            </Col>
        </Row>
        );

    <div>
        <Row>
            <Col md=2>
            </Col>
                <Col md=8>
                    (ReactRe.listToElement blogPosts) 
                </Col>
            <Col md=2>
            </Col>
        </Row>
    </div>;
    };
};

include ReactRe.CreateComponent Blog;

let createElement = wrapProps ();