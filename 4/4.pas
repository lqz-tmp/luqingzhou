var 
 a:array[1..30000]of longint;
 n,i,tmp:longint;

procedure qsort(l,r: longint);
  var
     i,j,mid,y: longint;
  begin
     i:=l;
     j:=r;
     mid:=a[(l+r) div 2];
     repeat
       while a[i]<mid do
        inc(i);
       while mid<a[j] do
        dec(j);
       if i<=j then
         begin
            y:=a[i];
            a[i]:=a[j];
            a[j]:=y;
            i:=i+1;
            j:=j-1;
         end;
     until i>j;
     if l<j then
       qsort(l,j);
     if i<r then
       qsort(i,r);
  end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  qsort(1,n);
  read(n);
  for i:=1 to n do
   begin
     read(tmp);
     writeln(a[tmp]);
   end;
end.