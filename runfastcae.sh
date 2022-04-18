 #docker run -d  -v $PWD:/data -p 5901:5901  --security-opt seccomp=unconfined--name fastcae alleindrach2/fastcae:v.0.01            

 docker run -d  -v $PWD:/data -p 5901:5901  --name  ubuntu ubuntu:18.04 /bin/bash -c "tail -f /dev/null"


 docker run 