gcc ride.c -o ride
cp ride.in1 ride.in
./ride
cat ride.out
mv ride.out ride.out1
cp ride.in2 ride.in
./ride
cat ride.out
mv ride.out ride.out2

