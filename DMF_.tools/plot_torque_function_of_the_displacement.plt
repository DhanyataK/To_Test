<?xml version='1.0' encoding='UTF-8'?>
<!DOCTYPE PLT>
<PLT DOC_VERSION="16.0.0">
    <PLOT_CFG>
        <WINDOW_GEOMETRY>378 208 637 759</WINDOW_GEOMETRY>
        <ITEMS_LIST>
            <ITEM type="dpv">
                <UNIT>null</UNIT>
                <NAME>A0</NAME>
                <REF_TITLE>angle</REF_TITLE>
            </ITEM>
            <ITEM type="dpv">
                <UNIT>Nm</UNIT>
                <NAME>A1</NAME>
                <REF_TITLE>T1@DMF</REF_TITLE>
            </ITEM>
            <ITEM type="dpv">
                <UNIT>Nm</UNIT>
                <NAME>A2</NAME>
                <REF_TITLE>T2@DMF</REF_TITLE>
            </ITEM>
            <ITEM type="dpv">
                <UNIT>s</UNIT>
                <NAME>A3</NAME>
                <REF_TITLE>ame_simulation_time</REF_TITLE>
            </ITEM>
        </ITEMS_LIST>
        <INPUT_ITEMS_LIST/>
        <COMPUTATION_LIST/>
        <PAGE_CFG>
            <NB_ROWS_COLUMNS>2 1</NB_ROWS_COLUMNS>
            <AREAS_LIST>
                <AREA>
                    <GEOMETRY>0 0 635 344</GEOMETRY>
                    <GRAPH_RENDERER type="2D Graph">
                        <MARGIN_COLOR>255 255 255</MARGIN_COLOR>
                        <MARGIN_SIZE>46 43 3 3 56 0 56 56</MARGIN_SIZE>
                        <AREA_COLOR>255 255 255</AREA_COLOR>
                        <IS_BOX_DRAWN>true</IS_BOX_DRAWN>
                        <BOX_PEN>200 200 200 1 1</BOX_PEN>
                        <X_AXIS>
                            <ZOOM>
                                <MIN>-65</MIN>
                                <MAX>65</MAX>
                            </ZOOM>
                            <TITLE>
                                <SHOW_BORDER>false</SHOW_BORDER>
                                <GRAPH_ANCHOR>13</GRAPH_ANCHOR>
                                <TEXT>X: relative angle [degree]</TEXT>
                                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>50 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </TITLE>
                            <PEN>0 0 0 1 1</PEN>
                            <FONT>
                                <FONT_FAMILY>Segoe UI</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>75 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <OPTIONS>
                                <POWER_MODE>-1</POWER_MODE>
                                <MAJOR_TICKS_MODE>-1</MAJOR_TICKS_MODE>
                                <MINOR_TICKS_MODE>-1</MINOR_TICKS_MODE>
                            </OPTIONS>
                            <SHOW_UNIT>false</SHOW_UNIT>
                            <DRAW_AXIS>true</DRAW_AXIS>
                            <MAJOR_GRID_PEN>200 200 200 3 1</MAJOR_GRID_PEN>
                            <MINOR_GRID_STYLE>3</MINOR_GRID_STYLE>
                            <MAJOR_GRID_DRAWN>true</MAJOR_GRID_DRAWN>
                            <MINOR_GRID_DRAWN>true</MINOR_GRID_DRAWN>
                        </X_AXIS>
                        <Y_AXIS>
                            <ZOOM/>
                            <PEN>0 0 0 1 1</PEN>
                            <FONT>
                                <FONT_FAMILY>Segoe UI</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>75 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <RANK>0</RANK>
                            <OPTIONS>
                                <POWER_MODE>-1</POWER_MODE>
                                <MAJOR_TICKS_MODE>-1</MAJOR_TICKS_MODE>
                                <MINOR_TICKS_MODE>-1</MINOR_TICKS_MODE>
                            </OPTIONS>
                            <SHOW_UNIT>true</SHOW_UNIT>
                            <DRAW_AXIS>true</DRAW_AXIS>
                            <MAJOR_GRID_PEN>200 200 200 3 1</MAJOR_GRID_PEN>
                            <MINOR_GRID_STYLE>3</MINOR_GRID_STYLE>
                            <MAJOR_GRID_DRAWN>true</MAJOR_GRID_DRAWN>
                            <MINOR_GRID_DRAWN>true</MINOR_GRID_DRAWN>
                        </Y_AXIS>
                    </GRAPH_RENDERER>
                    <CURVE type="2D curve">
                        <TITLE>
                            <TEXT>torque at flange&lt;ITEM_UNIT></TEXT>
                            <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                            <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                            <FONT_SIZE>8</FONT_SIZE>
                            <FONT_STYLE>50 0</FONT_STYLE>
                            <FONT_EFFECT>0 0</FONT_EFFECT>
                        </TITLE>
                        <ITEM>
                            <NAME>A0</NAME>
                        </ITEM>
                        <ITEM>
                            <NAME>A1</NAME>
                        </ITEM>
                        <CURVE_DISPLAY type="2D line">
                            <ARE_LINES_DRAWN>true</ARE_LINES_DRAWN>
                            <LINE_PEN>30 160 40 1 2 1</LINE_PEN>
                            <ARE_SYMBOLS_DRAWN>false</ARE_SYMBOLS_DRAWN>
                            <SYMBOLS_COLOR>237 11 0</SYMBOLS_COLOR>
                            <SYMBOLS_STYLE>4</SYMBOLS_STYLE>
                            <SYMBOLS_SIZE>1</SYMBOLS_SIZE>
                            <SYMBOLS_DENSITY>100</SYMBOLS_DENSITY>
                            <ARE_Z_SYMBOLS_DRAWN>true</ARE_Z_SYMBOLS_DRAWN>
                            <USER_CUSTOM_COLOR>true</USER_CUSTOM_COLOR>
                        </CURVE_DISPLAY>
                        <YAXIS_RANK>0 0</YAXIS_RANK>
                    </CURVE>
                    <GRAPH_TITLES_CONFIGURATION>
                        <IS_AUTOMATIC_MODE>0</IS_AUTOMATIC_MODE>
                        <IS_GRAPH_TITLE_SHOWN>false</IS_GRAPH_TITLE_SHOWN>
                        <IS_XAXIS_TITLE_SHOWN>true</IS_XAXIS_TITLE_SHOWN>
                        <IS_LEGEND_SHOWN>true</IS_LEGEND_SHOWN>
                        <IS_GRAPH_KEYS_SHOWN>true</IS_GRAPH_KEYS_SHOWN>
                        <LEGEND_POSITION>16</LEGEND_POSITION>
                        <TITLE_POSITION>2</TITLE_POSITION>
                        <X_AXIS_TITLE_POSITION>13</X_AXIS_TITLE_POSITION>
                    </GRAPH_TITLES_CONFIGURATION>
                    <GRAPH_TITLE>
                        <SHOW_BORDER>false</SHOW_BORDER>
                        <GRAPH_ANCHOR>2</GRAPH_ANCHOR>
                        <TEXT>&lt;COMPONENT_ALIAS> - &lt;ITEM_NAME> &lt;ITEM_UNIT></TEXT>
                        <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                        <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                        <FONT_SIZE>8</FONT_SIZE>
                        <FONT_STYLE>75 0</FONT_STYLE>
                        <FONT_EFFECT>0 0</FONT_EFFECT>
                    </GRAPH_TITLE>
                    <LEGEND>
                        <SHOW_BORDER>true</SHOW_BORDER>
                        <GRAPH_ANCHOR>16</GRAPH_ANCHOR>
                        <DEFAULT_TEXT_STYLE>
                            <COLOR>0 0 0</COLOR>
                            <FONT>
                                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>50 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <BORDER_SHOWN>true</BORDER_SHOWN>
                        </DEFAULT_TEXT_STYLE>
                    </LEGEND>
                    <DATA_SET_MODE>1</DATA_SET_MODE>
                </AREA>
                <AREA>
                    <GEOMETRY>0 344 635 344</GEOMETRY>
                    <GRAPH_RENDERER type="2D Graph">
                        <MARGIN_COLOR>255 255 255</MARGIN_COLOR>
                        <MARGIN_SIZE>46 43 3 3 56 0 56 56</MARGIN_SIZE>
                        <AREA_COLOR>255 255 255</AREA_COLOR>
                        <IS_BOX_DRAWN>true</IS_BOX_DRAWN>
                        <BOX_PEN>200 200 200 1 1</BOX_PEN>
                        <X_AXIS>
                            <ZOOM>
                                <MIN>-65</MIN>
                                <MAX>65</MAX>
                            </ZOOM>
                            <TITLE>
                                <SHOW_BORDER>false</SHOW_BORDER>
                                <GRAPH_ANCHOR>13</GRAPH_ANCHOR>
                                <TEXT>X: relative angle [degree]</TEXT>
                                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>50 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </TITLE>
                            <PEN>0 0 0 1 1</PEN>
                            <FONT>
                                <FONT_FAMILY>Segoe UI</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>75 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <OPTIONS>
                                <POWER_MODE>-1</POWER_MODE>
                                <MAJOR_TICKS_MODE>-1</MAJOR_TICKS_MODE>
                                <MINOR_TICKS_MODE>-1</MINOR_TICKS_MODE>
                            </OPTIONS>
                            <SHOW_UNIT>false</SHOW_UNIT>
                            <DRAW_AXIS>true</DRAW_AXIS>
                            <MAJOR_GRID_PEN>200 200 200 3 1</MAJOR_GRID_PEN>
                            <MINOR_GRID_STYLE>3</MINOR_GRID_STYLE>
                            <MAJOR_GRID_DRAWN>true</MAJOR_GRID_DRAWN>
                            <MINOR_GRID_DRAWN>true</MINOR_GRID_DRAWN>
                        </X_AXIS>
                        <Y_AXIS>
                            <ZOOM/>
                            <PEN>0 0 0 1 1</PEN>
                            <FONT>
                                <FONT_FAMILY>Segoe UI</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>75 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <RANK>0</RANK>
                            <OPTIONS>
                                <POWER_MODE>-1</POWER_MODE>
                                <MAJOR_TICKS_MODE>-1</MAJOR_TICKS_MODE>
                                <MINOR_TICKS_MODE>-1</MINOR_TICKS_MODE>
                            </OPTIONS>
                            <SHOW_UNIT>true</SHOW_UNIT>
                            <DRAW_AXIS>true</DRAW_AXIS>
                            <MAJOR_GRID_PEN>200 200 200 3 1</MAJOR_GRID_PEN>
                            <MINOR_GRID_STYLE>3</MINOR_GRID_STYLE>
                            <MAJOR_GRID_DRAWN>true</MAJOR_GRID_DRAWN>
                            <MINOR_GRID_DRAWN>true</MINOR_GRID_DRAWN>
                        </Y_AXIS>
                    </GRAPH_RENDERER>
                    <CURVE type="2D curve">
                        <TITLE>
                            <TEXT>&lt;COMPONENT_ALIAS> - torque at primary wheel &lt;ITEM_UNIT></TEXT>
                            <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                            <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                            <FONT_SIZE>8</FONT_SIZE>
                            <FONT_STYLE>50 0</FONT_STYLE>
                            <FONT_EFFECT>0 0</FONT_EFFECT>
                        </TITLE>
                        <ITEM>
                            <NAME>A0</NAME>
                        </ITEM>
                        <ITEM>
                            <NAME>A2</NAME>
                        </ITEM>
                        <CURVE_DISPLAY type="2D line">
                            <ARE_LINES_DRAWN>true</ARE_LINES_DRAWN>
                            <LINE_PEN>30 160 40 1 2 1</LINE_PEN>
                            <ARE_SYMBOLS_DRAWN>false</ARE_SYMBOLS_DRAWN>
                            <SYMBOLS_COLOR>237 11 0</SYMBOLS_COLOR>
                            <SYMBOLS_STYLE>4</SYMBOLS_STYLE>
                            <SYMBOLS_SIZE>1</SYMBOLS_SIZE>
                            <SYMBOLS_DENSITY>100</SYMBOLS_DENSITY>
                            <ARE_Z_SYMBOLS_DRAWN>true</ARE_Z_SYMBOLS_DRAWN>
                            <USER_CUSTOM_COLOR>true</USER_CUSTOM_COLOR>
                        </CURVE_DISPLAY>
                        <YAXIS_RANK>0 0</YAXIS_RANK>
                    </CURVE>
                    <GRAPH_TITLES_CONFIGURATION>
                        <IS_AUTOMATIC_MODE>0</IS_AUTOMATIC_MODE>
                        <IS_GRAPH_TITLE_SHOWN>false</IS_GRAPH_TITLE_SHOWN>
                        <IS_XAXIS_TITLE_SHOWN>true</IS_XAXIS_TITLE_SHOWN>
                        <IS_LEGEND_SHOWN>true</IS_LEGEND_SHOWN>
                        <IS_GRAPH_KEYS_SHOWN>true</IS_GRAPH_KEYS_SHOWN>
                        <LEGEND_POSITION>16</LEGEND_POSITION>
                        <TITLE_POSITION>2</TITLE_POSITION>
                        <X_AXIS_TITLE_POSITION>13</X_AXIS_TITLE_POSITION>
                    </GRAPH_TITLES_CONFIGURATION>
                    <GRAPH_TITLE>
                        <SHOW_BORDER>false</SHOW_BORDER>
                        <GRAPH_ANCHOR>2</GRAPH_ANCHOR>
                        <TEXT>&lt;COMPONENT_ALIAS> - &lt;ITEM_NAME> &lt;ITEM_UNIT></TEXT>
                        <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                        <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                        <FONT_SIZE>8</FONT_SIZE>
                        <FONT_STYLE>75 0</FONT_STYLE>
                        <FONT_EFFECT>0 0</FONT_EFFECT>
                    </GRAPH_TITLE>
                    <LEGEND>
                        <SHOW_BORDER>true</SHOW_BORDER>
                        <GRAPH_ANCHOR>16</GRAPH_ANCHOR>
                        <DEFAULT_TEXT_STYLE>
                            <COLOR>0 0 0</COLOR>
                            <FONT>
                                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                                <FONT_SIZE>8</FONT_SIZE>
                                <FONT_STYLE>50 0</FONT_STYLE>
                                <FONT_EFFECT>0 0</FONT_EFFECT>
                            </FONT>
                            <BORDER_SHOWN>true</BORDER_SHOWN>
                        </DEFAULT_TEXT_STYLE>
                    </LEGEND>
                    <DATA_SET_MODE>1</DATA_SET_MODE>
                </AREA>
            </AREAS_LIST>
            <LABEL>
                <POSITION>466 112</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>1</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>575 112</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>2</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>356 191</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>4</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>330 218</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>5</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>280 217</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>6</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>188 237</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>7</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>97 214</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>8</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>275 157</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>9</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>312 131</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>10</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>361 129</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>11</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
            <LABEL>
                <POSITION>494 166</POSITION>
                <GRAPH_ANCHOR>0</GRAPH_ANCHOR>
                <TEXT>3</TEXT>
                <RGB_FG_COLOR>0 0 0</RGB_FG_COLOR>
                <FONT_FAMILY>MS Shell Dlg 2</FONT_FAMILY>
                <FONT_SIZE>12</FONT_SIZE>
                <FONT_STYLE>75 0</FONT_STYLE>
                <FONT_EFFECT>0 0</FONT_EFFECT>
            </LABEL>
        </PAGE_CFG>
    </PLOT_CFG>
</PLT>
