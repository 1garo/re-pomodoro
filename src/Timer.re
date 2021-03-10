
open Utils;

[@react.component]
let make = (~seconds) => 
<div><span> {seconds |> formatTime |> s}</span> </div>