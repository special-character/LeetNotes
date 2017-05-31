open Pervasives;
open ReactRe;
open Markdown; 

module Home = {
    
    /*external _bind : (Js_json.t => state => option Js_json.t) => state => unit = "bind" [@@bs.send];*/
    include ReactRe.Component.Stateful;
    type props = {name: string}; 
    type contentItem = {
        .
        id: string,
        content: string
    };
    type state = {
        contentList : list contentItem  
    };
    /*external _bind : (Js_json.t => state => option Js_json.t) => state => unit = "bind" [@@bs.send];*/
    let name = "Home";

    let handleData data state => {
        let d = data;
        Js.log d;
        None
    };

    let getInitialState props => { 
        contentList : [ { pub id = "first"; pub content = "do this"; }] 
    };

    type tt;
    external _bind : (state => Js_json.t => option Js_json.t) => Js.null int => state => tt = "bind" [@@bs.send];

    let componentDidMount {state, setState, handler} => {        
        let data = Js_json.parse {| {"id" : "chris"} |};
        
        let c = Js.Null.empty;
        Js.log c;

        let b = _bind handleData c state;
        Js.log b; 

        let result = 
        b
        |> Ajax._then (Ajax.ajaxPost "http://localhost:8081/listUsers" data);
        
        Js.log result;  
        None; 
    };
    
    
    let render {state, props, updater} =>
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
            <Col md=4>
                <Panel header="Backend" bsStyle="primary">
                </Panel>
            </Col>
            <Col md=4>
                <Panel header="FrontEnd" bsStyle="danger">
                </Panel>
            </Col>
            <Col md=2>
            </Col>
        </Row>
        /*<Markdown markup=text />*/
    </div>;
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};