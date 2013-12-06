clear all;

%The number of comparisons must be altered to account for the number of
%records searched for 
num_comparisons = 2;

clear data;clear parameter;clear identifier;
close all; 

param_str = 'C:\\Users\\Brian\\test_data\\parameter_file.txt';
parameter = textread(param_str,'%s',-1,'delimiter','\t');

identifier_str = 'C:\\Users\\Brian\\test_data\\identifier_file.txt';
identifier = textread(identifier_str,'%s',-1,'delimiter','\t');



for n = 1:1:num_comparisons
    for k = 1:1:5
    str_temp = sprintf('C:\\Users\\Brian\\test_data\\testfile%i.txt',5*(n-1)+k);

    disp(str_temp);
    
    vec_temp = textread(str_temp,'%f');
    
    data{5*(n-1)+k,1} = vec_temp;
    
    
    end    
end


%% Initialize Plotted Data
 total_min = zeros(1,num_comparisons);
 right_min = zeros(1,num_comparisons);
 left_min = zeros(1,num_comparisons);
 vert_min = zeros(1,num_comparisons);
 horiz_min = zeros(1,num_comparisons);
 
 total_max = zeros(1,num_comparisons);
 right_max = zeros(1,num_comparisons);
 left_max = zeros(1,num_comparisons);
 vert_max = zeros(1,num_comparisons);
 horiz_max = zeros(1,num_comparisons);
 
 total_med = zeros(1,num_comparisons);
 right_med = zeros(1,num_comparisons);
 left_med = zeros(1,num_comparisons);
 vert_med = zeros(1,num_comparisons);
 horiz_med = zeros(1,num_comparisons);
 
 total_mean = zeros(1,num_comparisons);
 right_mean = zeros(1,num_comparisons);
 left_mean = zeros(1,num_comparisons);
 vert_mean = zeros(1,num_comparisons);
 horiz_mean = zeros(1,num_comparisons);
 
 name = cell(num_comparisons);
 major = cell(num_comparisons);
 gender = cell(num_comparisons);
 age = cell(num_comparisons);
 dom_hand = cell(num_comparisons);
 
 identification = cell(num_comparisons,1);
 
%% Get string identifiers for each data set

for n = 1:1:num_comparisons
    name1 = identifier{5*(n-1)+1};
    major1 = identifier{5*(n-1)+2};
    gender1 = identifier{5*(n-1)+3};
    age1 = identifier{5*(n-1)+4};
    dom_hand1 = identifier{5*(n-1)+5};
    
    
    if (~strcmp(name1,'ANY'))
        identification{n} = name1;
    else
        identify_temp = '';
        if (~strcmp(name1,'ANY'))
            identify_temp = strcat(identify_temp,name1,', ');
        end
        if (~strcmp(major1,'ANY'))
            identify_temp = strcat(identify_temp,major1,', ');
        end
        if (~strcmp(gender1,'A'))
            identify_temp = strcat(identify_temp,gender1,', ');
        end
        if (~strcmp(age1,'0'))
            identify_temp = strcat(identify_temp,age1,', ');
        end
        if (~strcmp(dom_hand1,'A'))
            identify_temp = strcat(identify_temp,dom_hand1);
        end
        
        identification{n} = identify_temp;
    end
    
end


%% Find minimum, maximum, median, mean value for each record

for n = 1:1:num_comparisons
    for k = 1:1:5
        temp_param = parameter(5*(n-1) + k);
        data_temp = cell2mat(data(5*(n-1)+k));
        
        if strcmp(temp_param, 'total')
            total_min(n) = min(data_temp);
            total_max(n) = max(data_temp);
            total_med(n) = median(data_temp);
            total_mean(n) = mean(data_temp);
        else if strcmp(temp_param, 'right')
                right_min(n) = min(data_temp);
                right_max(n) = max(data_temp);
                right_med(n) = median(data_temp);
                right_mean(n) = mean(data_temp);
            else if strcmp(temp_param, 'left')
                    left_min(n) = min(data_temp);
                    left_max(n) = max(data_temp);
                    left_med(n) = median(data_temp);
                    left_mean(n) = mean(data_temp);
                else if strcmp(temp_param, 'vertical')
                        vert_min(n) = min(data_temp);
                        vert_max(n) = max(data_temp);
                        vert_med(n) = median(data_temp);
                        vert_mean(n) = mean(data_temp);
                    else if strcmp(temp_param, 'horizontal')
                            horiz_min(n) = min(data_temp);
                            horiz_max(n) = max(data_temp);
                            horiz_med(n) = median(data_temp);
                            horiz_mean(n) = mean(data_temp);
                        end
                    end
                end
            end
        end
    end
end

totals = [total_min; total_max; total_med; total_mean];
right = [right_min; right_max; right_med; right_mean];
left = [left_min; left_max; left_med; left_mean];
vertical = [vert_min; vert_max; vert_med; vert_mean];
horizontal = [horiz_min; horiz_max; horiz_med; horiz_mean];

figure;set(gcf,'Position',get(0,'ScreenSize'));
subplot(2,2,1);bar(right);title('Right Hand Scores');set(gca,'XTickLabel',{'Minimum','Maximum','Median','Mean'});legend(identification);
subplot(2,2,2);bar(left);title('Left Hand Scores');set(gca,'XTickLabel',{'Minimum','Maximum','Median','Mean'});legend(identification);
subplot(2,2,3);bar(vertical);title('Vertical Hand Scores');set(gca,'XTickLabel',{'Minimum','Maximum','Median','Mean'});legend(identification);
subplot(2,2,4);bar(horizontal);title('Horizontal Hand Scores');set(gca,'XTickLabel',{'Minimum','Maximum','Median','Mean'});legend(identification);


%% Plot histograms

std_dev = zeros(5,num_comparisons);

for n = 1:1:num_comparisons
     for k = 1:1:5
        temp_param = parameter(5*(n-1) + k);
        data_temp = cell2mat(data(5*(n-1)+k)); 
        
        if strcmp(temp_param, 'total')
            [total_hist_temp, total_centers_temp] = hist(data_temp);
            total_hist(:,n) = total_hist_temp;
            total_centers(:,n) = total_centers_temp;
            std_dev(1,n) = std(data_temp);
        else if strcmp(temp_param, 'right')
                [right_hist_temp, right_centers_temp] = hist(data_temp);
                right_hist(:,n) = right_hist_temp;
                right_centers(:,n) = right_centers_temp;
                std_dev(2,n) = std(data_temp);
            else if strcmp(temp_param, 'left')
                    [left_hist_temp,left_centers_temp] = hist(data_temp);
                    left_hist(:,n) = left_hist_temp;
                    left_centers(:,n) = left_centers_temp;
                    std_dev(3,n) = std(data_temp);
                else if strcmp(temp_param, 'vertical')
                        [vertical_hist_temp, vertical_centers_temp] = hist(data_temp);
                        vertical_hist(:,n) = vertical_hist_temp;
                        vertical_centers(:,n) = vertical_centers_temp;
                        std_dev(4,n) = std(data_temp);
                    else if strcmp(temp_param, 'horizontal')
                            [horiz_hist_temp, horiz_centers_temp] = hist(data_temp);
                            horiz_hist(:,n) = horiz_hist_temp;
                            horiz_centers(:,n) = horiz_centers_temp;
                            std_dev(5,n) = std(data_temp);
                        end
                    end
                end
            end
        end
    end
end    

total_centers_final = total_centers(:,1);
right_centers_final = right_centers(:,1);
left_centers_final = left_centers(:,1);
vertical_centers_final = vertical_centers(:,1);
horiz_centers_final = horiz_centers(:,1);

for n = 2:1:num_comparisons
    total_centers_final = [total_centers_final;total_centers(:,n)];
    right_centers_final = [right_centers_final;right_centers(:,n)];
    left_centers_final = [left_centers_final;left_centers(:,n)];
    vertical_centers_final = [vertical_centers_final;vertical_centers(:,n)];
    horiz_centers_final = [horiz_centers_final;horiz_centers(:,n)];
end

centers_length = length(total_centers_final);

total_hist_final = zeros(centers_length,num_comparisons);
right_hist_final = zeros(centers_length,num_comparisons);
left_hist_final = zeros(centers_length,num_comparisons);
vertical_hist_final = zeros(centers_length,num_comparisons);
horiz_hist_final = zeros(centers_length,num_comparisons);

for n = 1:1:num_comparisons
    temp_length = length(total_hist(:,n));
    total_hist_final((n-1)*temp_length+1:n*temp_length,n) = total_hist(:,n);
    right_hist_final((n-1)*temp_length+1:n*temp_length,n) = total_hist(:,n);
    left_hist_final((n-1)*temp_length+1:n*temp_length,n) = total_hist(:,n);
    vertical_hist_final((n-1)*temp_length+1:n*temp_length,n) = total_hist(:,n);
    horiz_hist_final((n-1)*temp_length+1:n*temp_length,n) = total_hist(:,n);
end


%% Alternatively, it might actually look better to plot separate histograms of everything.

top_row = floor(num_comparisons/2);
bottom_row = num_comparisons - top_row;

right_max = max(max(right_hist));
left_max = max(max(left_hist));
vertical_max = max(max(vertical_hist));
horiz_max = max(max(horiz_hist));
total_max = max(max(total_hist));

figure;set(gcf,'Position',get(0,'ScreenSize'));
bar(totals);title('Total Scores');set(gca,'XTickLabel',{'Minimum','Maximum','Median','Mean'});legend(identification);

figure;set(gcf,'Position',get(0,'ScreenSize'));
for n=1:1:num_comparisons
    subplot(2,bottom_row,n);bar(total_centers(:,n),total_hist(:,n));title(identification{n});ylim([0 total_max+5]);
    temp_std = sprintf('Standard Deviation = %f',std_dev(1,n));
    temp_mean = sprintf('Mean = %f',total_mean(n));
    xlimits = xlim;
    text(xlimits(1) + 1,total_max + 3,temp_std);
    text(xlimits(1) + 1,total_max + 4,temp_mean);   
end
    [ax1,h1] = suplabel('Total Scores','t');
    set(h1,'FontSize',20);

figure;set(gcf,'Position',get(0,'ScreenSize'));
for n=1:1:num_comparisons
    subplot(2,bottom_row,n);bar(right_centers(:,n),right_hist(:,n));title(identification{n});ylim([0 right_max+5]);
    temp_std = sprintf('Standard Deviation = %f',std_dev(2,n));
    temp_mean = sprintf('Mean = %f',right_mean(n));
    xlimits = xlim;
    text(xlimits(1)+1,right_max + 3,temp_std);
    text(xlimits(1)+1,right_max + 4,temp_mean);   
end
    [ax1,h1] = suplabel('Right Hand Scores','t');
    set(h1,'FontSize',20);

figure;set(gcf,'Position',get(0,'ScreenSize'));
for n=1:1:num_comparisons
    subplot(2,bottom_row,n);bar(left_centers(:,n),left_hist(:,n));title(identification{n});ylim([0 left_max+5]);
    temp_std = sprintf('Standard Deviation = %f',std_dev(3,n));
    temp_mean = sprintf('Mean = %f',left_mean(n));
    xlimits = xlim;
    text(xlimits(1)+1,left_max + 3,temp_std);
    text(xlimits(1)+1,left_max + 4,temp_mean);  
end
    [ax1,h1] = suplabel('Left Hand Scores','t');
    set(h1,'FontSize',20);

figure;set(gcf,'Position',get(0,'ScreenSize'));
for n=1:1:num_comparisons
    subplot(2,bottom_row,n);bar(vertical_centers(:,n),vertical_hist(:,n));title(identification{n});ylim([0 vertical_max+5]);
    temp_std = sprintf('Standard Deviation = %f',std_dev(4,n));
    temp_mean = sprintf('Mean = %f',vert_mean(n));
    xlimits = xlim;
    text(xlimits(1)+1,vertical_max + 3,temp_std);
    text(xlimits(1)+1,vertical_max + 4,temp_mean);   
end
    [ax1,h1] = suplabel('Vertical Hand Scores','t');
    set(h1,'FontSize',20);
    
figure;set(gcf,'Position',get(0,'ScreenSize'));
for n=1:1:num_comparisons
    subplot(2,bottom_row,n);bar(horiz_centers(:,n),horiz_hist(:,n));title(identification{n});ylim([0 horiz_max+5]);
    temp_std = sprintf('Standard Deviation = %f',std_dev(5,n));
    temp_mean = sprintf('Mean = %f',horiz_mean(n));
    xlimits = xlim;
    text(xlimits(1)+1,horiz_max + 3,temp_std);
    text(xlimits(1)+1,horiz_max + 4,temp_mean); 
end
    [ax1,h1] = suplabel('Horizontal Hand Scores','t');
    set(h1,'FontSize',20);
    
    
    
