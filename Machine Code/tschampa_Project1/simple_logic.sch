<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="XLXN_5" />
        <signal name="C" />
        <signal name="XLXN_9" />
        <signal name="XLXN_12" />
        <signal name="XLXN_14" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="A" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="B" />
        <signal name="F" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="B" />
        <port polarity="Output" name="F" />
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <block symbolname="and2" name="XLXI_1">
            <blockpin signalname="A" name="I0" />
            <blockpin signalname="XLXN_20" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="B" name="I" />
            <blockpin signalname="XLXN_20" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_3">
            <blockpin signalname="XLXN_2" name="I0" />
            <blockpin signalname="XLXN_5" name="I1" />
            <blockpin signalname="F" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="B" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_5" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1808" y="1408" name="XLXI_3" orien="R0" />
        <branch name="XLXN_5">
            <wire x2="1808" y1="1248" y2="1280" x1="1808" />
        </branch>
        <instance x="1712" y="992" name="XLXI_4" orien="R90" />
        <branch name="C">
            <wire x2="1840" y1="560" y2="675" x1="1840" />
            <wire x2="1840" y1="675" y2="945" x1="1840" />
            <wire x2="1840" y1="945" y2="992" x1="1840" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1616" y1="1280" y2="1344" x1="1616" />
            <wire x2="1808" y1="1344" y2="1344" x1="1616" />
        </branch>
        <instance x="1520" y="1024" name="XLXI_1" orien="R90" />
        <branch name="A">
            <wire x2="1584" y1="576" y2="723" x1="1584" />
            <wire x2="1584" y1="723" y2="1024" x1="1584" />
        </branch>
        <branch name="XLXN_20">
            <wire x2="1648" y1="992" y2="1024" x1="1648" />
        </branch>
        <instance x="1616" y="768" name="XLXI_2" orien="R90" />
        <branch name="B">
            <wire x2="1648" y1="640" y2="688" x1="1648" />
            <wire x2="1648" y1="688" y2="719" x1="1648" />
            <wire x2="1648" y1="719" y2="768" x1="1648" />
            <wire x2="1712" y1="640" y2="640" x1="1648" />
            <wire x2="1776" y1="640" y2="640" x1="1712" />
            <wire x2="1776" y1="640" y2="722" x1="1776" />
            <wire x2="1776" y1="722" y2="735" x1="1776" />
            <wire x2="1776" y1="735" y2="992" x1="1776" />
            <wire x2="1712" y1="560" y2="608" x1="1712" />
            <wire x2="1712" y1="608" y2="640" x1="1712" />
        </branch>
        <iomarker fontsize="28" x="1584" y="576" name="A" orien="R270" />
        <iomarker fontsize="28" x="1712" y="560" name="B" orien="R270" />
        <iomarker fontsize="28" x="1840" y="560" name="C" orien="R270" />
        <branch name="F">
            <wire x2="2128" y1="1312" y2="1312" x1="2064" />
        </branch>
        <iomarker fontsize="28" x="2128" y="1312" name="F" orien="R0" />
    </sheet>
</drawing>