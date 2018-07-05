var
  a:array[0..100001] of longint;
  n,m,i,j,x,y:longint;
begin
  readln(m,n);
  for i:=1 to n do
   begin
     readln(y,x);
     for j:=x to m do
      if a[j-x]+y>a[j] then a[j]:=a[j-x]+y;
   end;
  writeln(a[m]);
end.