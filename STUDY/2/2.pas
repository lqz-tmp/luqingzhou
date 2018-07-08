var
  n,i,j,an,tmp,temp:integer;
  a:array[1..100] of integer;
begin
   read(n);
   temp:=10000;
   for i:=1 to n do
     read(a[i]);
   for i:= 2 to n-1 do
   begin
      j:=1;
      tmp:=0;
      while j<n do
        begin
          if j=i-1 then
            begin
              an:=abs(a[j]-a[j+2]);
              j:=j+2;
            end
          else
            begin
              an:=abs(a[j]-a[j+1]);
              j:=j+1;
            end;
          if an>tmp then tmp:=an;
        end;
      if tmp<temp then temp:=tmp;
   end;
   write(tmp);
end.
