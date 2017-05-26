open System.IO
open System

let readLines =
     Seq.initInfinite (fun _ -> System.Console.In.ReadLine())
     |> Seq.takeWhile(fun line -> line <> null);;

let computeOperation (data: int list) (op:string) = 
    
    let convToInt = op.Split([|' '|]) |>  Array.map (fun x -> x |> int )
    let convToSeq : seq<int> = Seq.cast convToInt  
    let result = Array.ofSeq convToSeq 

    let operator = result.[0]
  
    let result =  
        match operator with
        | 3 -> data
        | 2 -> List.tail data 
        | 1 -> List.append [result.[1]] data

    if operator = 3 then printfn "%i" (List.head (List.sortDescending data)) 

    result 

let iterList lines = 
       
    let finalOutput =
        lines
        |> List.ofSeq
        |> List.tail
        |> List.fold (fun x -> computeOperation x ) []

    0

iterList readLines