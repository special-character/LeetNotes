let lst = [7,2,3,1,9,18,14,22,35];

let rec insert = fun (x: int) (lst: list(int)) :list(int) => switch lst {
    | [] => [x]
    | [hd, ...tl] => x < hd ? [x,hd,...tl] : [hd]@(insert x [...tl]) 
};


let rec sort = fun l => switch l {
    | [] => []
    | [hd, ...tl] => insert hd (sort [...tl])
};

let print = fun lst => List.iter (fun s => ( print_endline (string_of_int(s)))) lst;
let sumList = fun lst => List.fold_left (fun acc x => acc + x) 0 lst; 

print (sort lst);
print_endline (string_of_int(sumList lst));