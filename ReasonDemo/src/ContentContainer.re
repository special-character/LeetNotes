open Pervasives;
open ReactRe;
open Markdown; 

module ContentContainer = {
    
    include ReactRe.Component.Stateful;
    type page =
      | AboutUs
      | Blog
      | InternalMetrics
      | Jobs; 
      
    type state = {
        currentPage : page
    };
    type props = unit;
    let name = "ContenteContainer";
    let getInitialState props => { 
        currentPage : Blog 
    };

    
    let render {state, props, updater} => {

    let { currentPage } = state;

    let pageToRender =
        switch currentPage {
        | Blog => <Blog />
        | _    => <Blog />
    };

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
            {pageToRender}
        </Row>
    </div>;
    };
};

include ReactRe.CreateComponent ContentContainer;

let createElement = wrapProps ();