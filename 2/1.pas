var
 a:array[1..35,1..35] of longint;
 i,j,m,n:integer;
begin
  read(m,n);
  for i:=1 to m do begin a[i,1]:=1; a[i,i]:=1; end;
  for i:=3 to m do
    for j:=2 to i-1 do a[i,j]:=a[i-1,j]+a[i-1,j-1];
  write(a[m,n]);
end.