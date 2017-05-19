open Pervasives;
open ReactRe;

module Home = {
    include ReactRe.Component;
    type props = {name: string}; 
    let name = "Home";

    let render {state, props, updater} =>
    <div>
        <Navigation name="MedInsight Engineering" pages={["About Us","Blog","Jobs"]}/>
    </div>;
};

include ReactRe.CreateComponent Home;

let createElement ::name => wrapProps {name: name};