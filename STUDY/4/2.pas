var
 a:array [1..1000] of integer;
 i,n,t:integer;
begin
 read(n);
 fillchar(a,sizeof(a),0);
 for i:=1 to n do begin read(t); a[t]:=1; end;
 t:=0;
 for i:=1 to 1000 do if a[i]=1 then t:=t+1;
 writeln(t);
 for i:=1 to 1000 do if a[i]=1 then write(i,' ');
end.
