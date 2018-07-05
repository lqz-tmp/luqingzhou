var
 x,xt:array[1..100000] of longint;
 i,n,h,tmp,ac,an,nn:longint;
procedure jh;
var j:longint;
  begin
   for j:=h to n do x[i]:=xt[i];
  end;
function mix(a,b:longint):longint;
 begin
  if a<b then a:=b;
  exit(a);
 end;
begin
an:=0;
 read(n);
 nn:=n;
 h:=1;
 for i:=1 to n do
   begin
   read(x[i]);
   xt[i]:=x[i];
   end;
 ac:=1;
 while(ac=1) do
   begin
   xt[h]:=0;
   xt[n]:=0;
   for i:=h+1 to n-1 do
      begin
        tmp:=mix(x[i-1],x[i+1]);
        if x[i]>tmp then xt[i]:=tmp
        else dec(xt[i]);
      end;
   jh;
   for i:=1 to nn do if x[i]>0 then h:=i;
   for i:=nn downto 1 do if x[i]>0 then n:=i;
   ac:=0;
   an:=an+1;
   for i:= h to n do if x[i]>0 then ac:=1;
  end;
  write(an);
end.
