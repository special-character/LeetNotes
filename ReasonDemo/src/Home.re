open Pervasives;
open ReactRe;
open Markdown; 

module Home = {
    
    include ReactRe.Component.Stateful;
    type props = {name: string}; 
    type contentItem = {
        id: string,
        content: string,
        author: string,
        blogType: string
    };
    type state = {
        contentList : list contentItem  
    };
    let name = "Home";

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
            <Panel header="Backend" bsStyle="primary">
                <Markdown markup=x.content/>
            </Panel>
        </Col>
        );

    <div>
        <Navigation name="MedInsight Engineering" pages={["About Us","Blog","Internal Metrics","Jobs"]}/>
        <Row>
            <Col md=2>
            </Col>
                <Col md=8>
                    <Jumbotron>
                        <h2>(ReactRe.stringToElement "Home of MedInsight Engineering")</h2>
                    </Jumbotron>
                </Col>
            <Col md=2>
            </Col>
        </Row>
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

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};