var
x:array[-100000..100000] of longint;
i,an,tmp,lastl,lastr,a1,a2,l,r,n,ans,anst,lt,rt:longint;
function y(i:longint):longint;
  var j:longint;
  begin
  tmp:=x[i];
  j:=i;
  while tmp=0 do
    begin
    if j>0 then inc(j);
    if j<0 then dec(j);
    if (j>100000)or(j<-100000) then exit(0);
    tmp:=x[j];
    end;
  exit(j);
  end;
begin
  read(an);
  a1:=0;
  a2:=0;
  for i:=1 to an do
     begin
     read(tmp);
     read(x[tmp]);
     readln;
     if tmp<0 then l:=l+1;
     if tmp>0 then r:=r+1;
     end;
   lt:=l;
   rt:=r;
   lastl:=0;
   lastr:=0;
   n:=1;
  tmp:=1;
  while (tmp>0) do
    begin
     if n=1 then
      begin an:=y(lastr+1); r:=r-1;lastr:=an; end
     else begin an:=y(lastl-1); l:=l-1;lastl:=an; end;
     n:=-1*n;
     if n<0 then tmp:=l else tmp:=r;
     ans:=ans+x[an];
    end;
   lastl:=0;
   lastr:=0;
   n:=-1;
tmp:=1;
  while (tmp>0) do
    begin
     if n=1 then
      begin an:=y(lastr+1); rt:=rt-1;lastr:=an; end
     else begin an:=y(lastl-1); lt:=lt-1;lastl:=an; end;
     n:=-1*n;
      if n<0 then tmp:=lt else tmp:=rt;
     anst:=anst+x[an];
    end;
  if ans<anst then ans:=anst;
  write(ans);
end.