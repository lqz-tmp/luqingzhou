var
 a:array [1..100000] of longint;
 i,n,t,max:longint;
begin
 read(n);
 max:=0;
 fillchar(a,sizeof(a),0);
 for i:=1 to n do begin read(t); a[t]:=a[t]+1; end;
 for i:=1 to 100000 do if a[i]>max then max:=a[i];
 for i:=1 to 100000 do if a[i]=max then writeln(i,'  ',a[i]);
end.