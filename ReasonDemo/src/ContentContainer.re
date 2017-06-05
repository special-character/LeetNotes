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

    let convertStringToPage str => {
        switch str {
        | "About Us" => AboutUs
        | "Blog" => Blog
        | "Internal Metrics" => InternalMetrics
        | "Jobs" => Jobs
        };
    };
    
    let render {state, props, updater} => {

    let { currentPage } = state;

    let pageToRender =
        switch currentPage {
        | Blog => <Blog />
        | AboutUs => <AboutUs />
        | _    => <Blog />
    };
    
    let switchPage {state, props} event => {
        
        let newPage =
        switch event {
        | "About Us" => AboutUs
        | "Blog" => Blog
        | "Internal Metrics" => Blog
        | "Jobs" => Blog
        };


        ((convertStringToPage event) == state.currentPage )
        ? None  
        : Some {...state, currentPage: newPage };
    };

    <div>
        <Navigation name="MedInsight Engineering" pageHandler=(updater switchPage) pages={["Blog","About Us","Internal Metrics","Jobs"]} />
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