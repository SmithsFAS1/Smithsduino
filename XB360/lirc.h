/*
# this config file was automatically generated
# using lirc-0.8.0-CVS(mceusb2) on Tue Jan 17 15:14:11 2006
#
# contributed by Kyle at shadowmage.org
#
# brand: Microsoft
# model no. of remote control: Xbox 360 Universal Media Remote
# devices being controlled by this remote: Xbox 360
#
# This probably works for the normal Xbox 360 remote too.
#
# TV button sends no signal and toggles Xbox 360/TV mode. TV mode can be
# signals for any device the remote supports. Volume Up, Volume Down and
# Mute always use the TV mode while the Xbox live guide button always sends
# to the xbox.

begin remote

  name  Microsoft_Xbox360
  bits           16
  flags RC6|CONST_LENGTH
  eps            30
  aeps          100

  header       2676   870
  one           454   429
  zero          454   429
  pre_data_bits   21
  pre_data       0x37FF0
  gap          106291
  min_repeat      1
  toggle_bit_mask 0x8000

  rc6_mask    0x100000000

      begin codes
          KEY_OPEN                 0x8BD7                    #  Was: OpenClose
          XboxFancyButton          0x0B9B
          KEY_POWER                0x8BF3                    #  Was: OnOff
          KEY_STOP                 0x0BE6                    #  Was: Stop
          KEY_PAUSE                0x8BE7                    #  Was: Pause
          KEY_REWIND               0x0BEA                    #  Was: Rewind
          KEY_FASTFORWARD          0x8BEB                    #  Was: FastForward
          KEY_PREVIOUS             0x0BE4                    #  Was: Prev
          KEY_NEXT                 0x8BE5                    #  Was: Next
          KEY_PLAY                 0x0BE9                    #  Was: Play
          Display                  0x8BB0
          KEY_TITLE                0x0BAE                    #  Was: Title
          KEY_MENU                 0x8BDB                    #  Was: DVD_Menu
          KEY_BACK                 0x0BDC                    #  Was: Back
          KEY_INFO                 0x8BF0                    #  Was: Info
          UpArrow                  0x0BE1
          LeftArrow                0x8BDF
          RightArrow               0x0BDE
          DownArrow                0x8BE0
          KEY_OK                   0x0BDD                    #  Was: OK
          KEY_Y                    0x8BD9                    #  Was: Y
          KEY_X                    0x0B97                    #  Was: X
          KEY_A                    0x8B99                    #  Was: A
          KEY_B                    0x0BDA                    #  Was: B
          KEY_CHANNELUP            0x8BED                    #  Was: ChUp
          KEY_CHANNELDOWN          0x0BEC                    #  Was: ChDown

          KEY_VOLUMEDOWN           0x0BEE                    #  Was: VolDown
          KEY_VOLUMEUP             0x0BEF                    #  Was: VolUp
          KEY_MUTE                 0x0BF1                    #  Was: Mute

          Start                    0x0BF2                    #  Was: Start
          KEY_ENTER                0x0BF4                    #  Was: Enter
          KEY_RECORD               0x8BE8                    #  Was: Record
          KEY_CLEAR                0x0BF5                    #  Was: Clear
          KEY_1                    0x8BFE                    #  Was: 1
          KEY_2                    0x0BFD                    #  Was: 2
          KEY_3                    0x8BFC                    #  Was: 3
          KEY_4                    0x0BFB                    #  Was: 4
          KEY_5                    0x8BFA                    #  Was: 5
          KEY_6                    0x0BF9                    #  Was: 6
          KEY_7                    0x8BF8                    #  Was: 7
          KEY_8                    0x0BF7                    #  Was: 8
          KEY_9                    0x8BF6                    #  Was: 9
          X_KEY_100                0x0BE2                    #  Was: 100
          KEY_0                    0x8BFF                    #  Was: 0
          Reload                   0x8BE3
          KEY_PLAY                 0x8BE9                    #  Was: Play, duplicate
      end codes

end remote


*/