let lst = [7,2,3,1,7,18,3,22,35];
let a = List.length lst;

let bb = fun x => x;
let rec insert = fun (x: int) (lst: list(int)) :list(int) => switch lst {
    | [] => [x]
    | [hd, ...tl] => x < hd ? [x,hd,...tl] : [hd]@(insert x [...tl]) 
};


let rec sort = fun l => switch l {
    | [] => []
    | [hd, ...tl] => insert hd (sort [...tl])
};

let result = sort lst;
let fifthElement = List.nth result 5;

print_endline (string_of_int(fifthElement))