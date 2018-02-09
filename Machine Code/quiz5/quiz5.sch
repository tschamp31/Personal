<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="artix7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_1" />
        <signal name="n0" />
        <signal name="n1" />
        <signal name="XLXN_5" />
        <signal name="s1" />
        <signal name="X" />
        <signal name="Y" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="XLXN_18" />
        <signal name="XLXN_19" />
        <signal name="XLXN_20" />
        <signal name="XLXN_21" />
        <signal name="XLXN_25" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="XLXN_30" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="XLXN_34" />
        <signal name="XLXN_35" />
        <signal name="s0" />
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
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
        <block symbolname="xor2" name="XLXI_1">
            <blockpin signalname="s1" name="I0" />
            <blockpin signalname="X" name="I1" />
            <blockpin signalname="n1" name="O" />
        </block>
        <block symbolname="or2" name="XLXI_11">
            <blockpin signalname="s0" name="I0" />
            <blockpin signalname="s1" name="I1" />
            <blockpin signalname="Y" name="O" />
        </block>
        <block symbolname="xor2" name="XLXI_12">
            <blockpin signalname="s0" name="I0" />
            <blockpin signalname="s1" name="I1" />
            <blockpin signalname="n0" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="s1">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1264" y="1429" type="branch" />
            <wire x2="1456" y1="944" y2="944" x1="1264" />
            <wire x2="1264" y1="944" y2="1136" x1="1264" />
            <wire x2="1264" y1="1136" y2="1376" x1="1264" />
            <wire x2="1264" y1="1376" y2="1386" x1="1264" />
            <wire x2="1264" y1="1386" y2="1429" x1="1264" />
            <wire x2="1264" y1="1429" y2="1472" x1="1264" />
            <wire x2="1440" y1="1376" y2="1376" x1="1264" />
            <wire x2="1440" y1="1136" y2="1136" x1="1264" />
        </branch>
        <branch name="X">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1152" y="1072" type="branch" />
            <wire x2="1152" y1="1072" y2="1072" x1="1120" />
            <wire x2="1440" y1="1072" y2="1072" x1="1152" />
        </branch>
        <branch name="Y">
            <attrtext style="alignment:SOFT-LEFT;fontsize:28;fontname:Arial" attrname="Name" x="1936" y="976" type="branch" />
            <wire x2="1936" y1="976" y2="976" x1="1712" />
        </branch>
        <instance x="1440" y="1200" name="XLXI_1" orien="R0" />
        <branch name="n1">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1760" y="1395" type="branch" />
            <wire x2="1264" y1="1552" y2="1632" x1="1264" />
            <wire x2="1760" y1="1632" y2="1632" x1="1264" />
            <wire x2="1760" y1="1104" y2="1104" x1="1696" />
            <wire x2="1760" y1="1104" y2="1395" x1="1760" />
            <wire x2="1760" y1="1395" y2="1632" x1="1760" />
        </branch>
        <branch name="n0">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1696" y="1425" type="branch" />
            <wire x2="1328" y1="1552" y2="1568" x1="1328" />
            <wire x2="1696" y1="1568" y2="1568" x1="1328" />
            <wire x2="1696" y1="1408" y2="1425" x1="1696" />
            <wire x2="1696" y1="1425" y2="1568" x1="1696" />
        </branch>
        <instance x="1456" y="1072" name="XLXI_11" orien="R0" />
        <branch name="s0">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1328" y="1399" type="branch" />
            <wire x2="1456" y1="1008" y2="1008" x1="1328" />
            <wire x2="1328" y1="1008" y2="1399" x1="1328" />
            <wire x2="1328" y1="1399" y2="1440" x1="1328" />
            <wire x2="1440" y1="1440" y2="1440" x1="1328" />
            <wire x2="1328" y1="1440" y2="1472" x1="1328" />
        </branch>
        <instance x="1440" y="1504" name="XLXI_12" orien="R0" />
    </sheet>
</drawing>