scp ./* daq@TC-DAQ:/home/daq/TC-3/
plink.exe -ssh daq@TC-DAQ -i "C:\SPB_Data\.ssh\id_rsa.ppk"  "cd ~/TC-3 && make -j4 ALL"
