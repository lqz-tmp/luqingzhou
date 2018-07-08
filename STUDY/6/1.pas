var
	a,b,c:string;
	i,j,k,m,an,last:longint;
	t:array[1..2000] of byte;
begin
	readln(m);
	for i:=1 to m do 
	 begin
	 	readln(a);
	 	readln(b);
	 	readln(c);
	 	an:=0;
	 	for j:=1 to length(c) do t[j]:=0;
	 	last:=0;
	 	for j:=1 to length(a) do
	 	  for k:=last+1 to length(c) do if (a[j]=c[k])and(t[k]=0) then begin t[k]:=1;last:=k;break;end;
	 		 	for j:=1 to length(c) do writeln(t[j]);
	 	last:=0;
	 	for j:=1 to length(b) do
	 	  for k:=last+1 to length(c) do if (b[j]=c[k])and(t[k]=0) then begin t[k]:=1;last:=k;break;end;
	 	for j:=1 to length(c) do if t[j]=0 then begin an:=1;break;end;
	 	for j:=1 to length(c) do writeln(t[j]);
	 	if an=1 then writeln('No') else writeln('Yes');
	 end;
end.