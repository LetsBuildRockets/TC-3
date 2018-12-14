hold off
clf('reset')
[data text]=importdata('data/dat_89.csv');
x= str2double(data.textdata(:,1));
x=x-x(2);
len = 1;
b = ones(len,1)/len;
m = [6,14,16,5,15,12];
rangeX = [0, inf];
fprintf("range: %.2f sec\n",rangeX(2)-rangeX(1));
for n = m
    col1 = data.data(:, n+1);
    if n == 12
        col1 = col1*20;
    end
    I = ~isnan(col1) & ~isnan(x)& rangeX(1)<x & x<rangeX(2);
    hold on
    plot(x(I), filter(b,1,flip(filter(b,1,flip(col1(I))))) ,'-')
    fprintf("mean col %d: %.2f\n",n,mean(col1(I)));
end
axis tight
legend(string(m))