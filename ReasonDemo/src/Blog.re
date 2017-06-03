open Pervasives;
open ReactRe;
open Markdown; 

module Blog = {
    
    include ReactRe.Component.Stateful;
    type contentItem = {
        id: string,
        content: string,
        author: string,
        blogType: string
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
                                       blogType:bp##blogType
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
        |> Ajax._then (Ajax.ajaxPost "http://localhost:2878/api/Blog/blogs" );
        None; 
    };
    
    let render {state, props, updater} => {

    let { contentList } = state;

    let md = MarkdownConverter.mdInit();
    
    let comps =
        contentList
        |> List.map (fun x =>  
        <Col md=4>
            <Panel header=(x.author ^ " : " ^ x.blogType) bsStyle="primary">
                <Markdown markup=x.content/>
            </Panel>
        </Col>
        );

    <div>
        <Row>
            <Col md=2>
            </Col>
            (ReactRe.listToElement comps) 
            <Col md=2>
            </Col>
        </Row>
    </div>;
    };
};

include ReactRe.CreateComponent Blog;

let createElement = wrapProps ();