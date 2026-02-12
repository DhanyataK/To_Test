<?xml version="1.0" encoding="UTF-8"?>
<PL DOC_VERSION="1" VersionId="20261.." checksum="1052730276">
 <PARAMS_LIST>
  <PARAMETER Data_Path="theta@rotaryspring" IS_DELTA="false" IS_LINKED_VARIABLE="false" Param_Id="2449" Submodel_Instance="1" Submodel_Name="RSPR00" TITLE="angular twist in spring" UNITS="degree" VALUE="0"/>
  <PARAMETER Data_Path="k@rotaryspring" IS_DELTA="false" Param_Id="2448" Submodel_Instance="1" Submodel_Name="RSPR00" TITLE="spring stiffness" TUNABLE="false" UNITS="Nm/degree" VALUE="1000"/>
  <PARAMETER Data_Path="tzero@zerotorquesource" IS_DELTA="false" IS_LINKED_VARIABLE="false" Param_Id="2459" Submodel_Instance="1" Submodel_Name="T000" TITLE="torque (always zero)" UNITS="Nm" VALUE="0"/>
  <PARAMETER Data_Path="xminslope@dynamic_time_table" IS_DELTA="false" Param_Id="2390" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="slope for x &lt; xmin" TUNABLE="false" UNITS="null" VALUE="0"/>
  <PARAMETER Data_Path="xmaxslope@dynamic_time_table" IS_DELTA="false" Param_Id="2391" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="slope for x > xmax" TUNABLE="false" UNITS="null" VALUE="0"/>
  <PARAMETER Data_Path="spline@dynamic_time_table" Param_Id="2392" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="interpolation type" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="lmode@dynamic_time_table" Param_Id="2393" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="linear data out of range mode" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="disc@dynamic_time_table" Param_Id="2394" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="discontinuity handling" TUNABLE="false" VALUE="2"/>
  <PARAMETER Data_Path="bcond@dynamic_time_table" Param_Id="2395" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="boundary conditions" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="cmode@dynamic_time_table" Param_Id="2396" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="cubic data out of range mode" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="outputtype@dynamic_time_table" Param_Id="2397" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="output value" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="ucol@dynamic_time_table" Param_Id="2398" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="column to use for u" TUNABLE="false" VALUE="2"/>
  <PARAMETER Data_Path="smode@dynamic_time_table" Param_Id="2399" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="stairs data out of range mode" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="initMethod@dynamic_time_table" Param_Id="2400" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="initialization method" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="tcol@dynamic_time_table" Param_Id="2401" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="column to use for time" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="filename@dynamic_time_table" Param_Id="2402" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="name of ASCII file" TUNABLE="false" VALUE="F11"/>
  <PARAMETER Data_Path="numOutputs@dynamic_time_table" Param_Id="0" Submodel_Instance="1" Submodel_Name="SIGUDA01" TITLE="number of outputs" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="w@rotaryload2ports" IS_DELTA="false" IS_LINKED_VARIABLE="false" Param_Id="2422" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="shaft speed at port 2" UNITS="rev/min" VALUE="0"/>
  <PARAMETER Data_Path="J@rotaryload2ports" IS_DELTA="false" Param_Id="2406" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="moment of inertia" TUNABLE="false" UNITS="kgm**2" VALUE="0.17"/>
  <PARAMETER Data_Path="vis@rotaryload2ports" IS_DELTA="false" Param_Id="2407" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="coefficient of viscous friction" TUNABLE="false" UNITS="Nm/(rev/min)" VALUE="1"/>
  <PARAMETER Data_Path="coul@rotaryload2ports" IS_DELTA="false" Param_Id="2408" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="Coulomb friction torque" TUNABLE="false" UNITS="Nm" VALUE="0"/>
  <PARAMETER Data_Path="stict@rotaryload2ports" IS_DELTA="false" Param_Id="2409" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="stiction torque" TUNABLE="false" UNITS="Nm" VALUE="0"/>
  <PARAMETER Data_Path="wind@rotaryload2ports" IS_DELTA="false" Param_Id="2410" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="coefficient of windage" TUNABLE="false" UNITS="Nm/(rev/min)**2" VALUE="0"/>
  <PARAMETER Data_Path="friction@rotaryload2ports" Param_Id="2411" Submodel_Instance="1" Submodel_Name="MECRL0" TITLE="use friction" TUNABLE="false" VALUE="1"/>
  <PARAMETER Data_Path="w@component_1_rotaryload2ports_1" IS_DELTA="false" IS_LINKED_VARIABLE="false" Param_Id="2443" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="shaft speed at port 2" UNITS="rev/min" VALUE="0"/>
  <PARAMETER Data_Path="J@component_1_rotaryload2ports_1" IS_DELTA="false" Param_Id="2427" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="moment of inertia" TUNABLE="false" UNITS="kgm**2" VALUE="0.17"/>
  <PARAMETER Data_Path="vis@component_1_rotaryload2ports_1" IS_DELTA="false" Param_Id="2428" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="coefficient of viscous friction" TUNABLE="false" UNITS="Nm/(rev/min)" VALUE="1"/>
  <PARAMETER Data_Path="coul@component_1_rotaryload2ports_1" IS_DELTA="false" Param_Id="2429" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="Coulomb friction torque" TUNABLE="false" UNITS="Nm" VALUE="0"/>
  <PARAMETER Data_Path="stict@component_1_rotaryload2ports_1" IS_DELTA="false" Param_Id="2430" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="stiction torque" TUNABLE="false" UNITS="Nm" VALUE="0"/>
  <PARAMETER Data_Path="wind@component_1_rotaryload2ports_1" IS_DELTA="false" Param_Id="2431" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="coefficient of windage" TUNABLE="false" UNITS="Nm/(rev/min)**2" VALUE="0"/>
  <PARAMETER Data_Path="friction@component_1_rotaryload2ports_1" Param_Id="2432" Submodel_Instance="2" Submodel_Name="MECRL0" TITLE="use friction" TUNABLE="false" VALUE="1"/>
 </PARAMS_LIST>
 <EXPOSED_COPY_LIST/>
 <GLOBAL_PARAMS_LIST>
  <PARAMETER Data_Path="F11" Param_Id="0" TITLE="name of ASCII file" TUNABLE="false" VALUE="collision_.UserData/Torque1.data"/>
  <PARAMETER Data_Path="F12" Param_Id="0" TITLE="name of ASCII file" TUNABLE="false" VALUE="collision_.UserData/Torque2.data"/>
  <PARAMETER Data_Path="F13" Param_Id="0" TITLE="name of ASCII file" TUNABLE="false" VALUE="collision_.UserData/Torque3.data"/>
 </GLOBAL_PARAMS_LIST>
 <GLOBAL_LOCAL_PARAMS_LIST/>
</PL>
