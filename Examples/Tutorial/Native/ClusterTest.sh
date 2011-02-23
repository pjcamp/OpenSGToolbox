#!/bin/sh

HORZ_SERVER_COUNT=2
VERT_SERVER_COUNT=2

SERVER_WIN_WIDTH=600
SERVER_WIN_HEIGHT=400

SERVER_WIN_TOP=560
SERVER_WIN_LEFT=200

SERVER_EXE_DIR=.
CLIENT_EXE_DIR=.

#SCENE_FILE=../UserInterface/Data/53LoadGUI.xml
#SCENE_FILE=../Animation/Data/Collada/Nanobot.dae
#SCENE_FILE=../ParticleSystem/Data/ParticleSystemExport.xml
#SCENE_FILE=../FieldContainerEditor/FgExport.xml
SCENE_FILE=./ViewportExport.xml

SERVERS=""

for ((  j = 0 ;  j < $VERT_SERVER_COUNT;  j++  ))
do
    for ((  i = 0 ;  i < $HORZ_SERVER_COUNT;  i++  ))
    do
        ServerName="test-${i}x${j}"
        SERVERS="$SERVERS $ServerName"
        XPos=`echo "$SERVER_WIN_LEFT + ($SERVER_WIN_WIDTH * $i)" | bc`
        YPos=`echo "$SERVER_WIN_TOP - ($SERVER_WIN_HEIGHT * $j)" | bc`
        $SERVER_EXE_DIR/05ClusterServer -m -w $SERVER_WIN_WIDTH -h $SERVER_WIN_HEIGHT -x $XPos -y $YPos $ServerName &
    done
done

echo "$SERVERS"
$CLIENT_EXE_DIR/06ClusterClient -m -x $HORZ_SERVER_COUNT -y $VERT_SERVER_COUNT -f $SCENE_FILE $SERVERS
