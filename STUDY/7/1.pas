var
	n,i,j,k,cn,t:longint;
	s:string;
	c:char;
	a:array[1..100000]of string;
	b:array[1..100000]of longint;
	tmp:array[1..40]of char;
procedure zl();
begin
	for j:=1 to length(s)-1 do
	  for k:=j+1 to length(s) do 
	    if s[j]>s[k] then begin c:=s[j];s[j]:=s[k];s[k]:=c; end; 
end;
begin
	readln(n);
	cn:=0;
	for i:=1 to n do 
	 begin
	 	readln(s);
	 	zl;
	 	t:=0;
	 	for j:=1 to cn do 
	 	   if a[j]=s then
	 	     begin
	 	     t:=t+b[j];
	 	     b[j]:=b[j]+1;
	 	     end;
	    writeln(t);
	 	if t=0 then begin cn:=cn+1; a[cn]:=s;b[cn]:=1;end;
	 end;
end.